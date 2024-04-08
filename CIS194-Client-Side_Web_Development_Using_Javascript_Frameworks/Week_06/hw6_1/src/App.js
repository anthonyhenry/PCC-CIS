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

const useMyCustomHook = (key, initialState) => {
   // State Hook
   const [value, setValue] = React.useState(
      localStorage.getItem(key) || initialState
   );

   // Side Effect Hook
   React.useEffect(
      ()=> {
         localStorage.setItem(key, value);
      }, 
      [key, value]
   );

   // Return array for destructuring
   return [value, setValue];
};

const App = () => {
  const hello_world = new Sentence('Hello', 'World!');
  const react_rocks = new Sentence('React', 'rocks!');

  const [checkTerm, setCheckTerm] = useMyCustomHook(
    'React', 
    'Redux'
  );

  const handleInput = evt => {
    setCheckTerm(evt.target.value);
    console.log(evt.target.value);
  };

  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          {/* creating/instantiating an instance of List component */}
          <List first={hello_world} second={react_rocks} />
        </p>
        <p>
          <Input onInput={handleInput} userInput={checkTerm} />
        </p>
      </header>
    </div>
  );
};

const Input = ({ onInput, userInput }) => (
  <> 
    <label htmlFor="Check">Check: </label>
    <input id="check" type="text" value={userInput} onChange={onInput} />
    <p>Checking for <b>{userInput}</b></p>
  </>
)

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