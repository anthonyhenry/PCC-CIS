import logo from './logo.svg';
import './App.css';
import React from 'react';

class Sentence {
  constructor(word1, word2) {
    this.word1 = word1;
    this.word2 = word2;
  }
  getSentence() {
    return this.word1 + ' ' + this.word2;
  }
}

const App = () => {
  
  // This is a synthestic event
  const handleInput = evt => {
    setCheckTerm(evt.target.value);
    console.log(evt.target.value);
    // Set local storage input
    localStorage.setItem('input', evt.target.value)
  };

  const hello_world = new Sentence('Hello', 'World!');
  const react_rocks = new Sentence('React', 'rocks!');

  const [checkTerm, setCheckTerm] = React.useState(
    // Set term to input saved in local storage or nothing if local storage is empty 
    localStorage.getItem('input') || "nothing"
  );
  
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          {/* creating/instantiating an instance of List component */}
          <List first={hello_world} second={react_rocks} />
        </p>
        <p>
          <Input onInput = {handleInput} userInput = {checkTerm} />
        </p>
      </header>
    </div>
  );
};

const Input = props => {  
  return (
    <div>
      <label htmlFor="Check">Check: </label>
      {/* <input id="check" type="text" onChange={props.onInput} /> */}
      <input id="check" type="text" value={props.userInput} onChange={props.onInput} />
      <p>Checking for <b>{props.userInput}</b></p>
    </div>
  );
}

const List = props => {
  return (
    <div>
      {props.first.getSentence()}
      <hr />
      {props.second.getSentence()}
    </div>
  );
};

export default App;