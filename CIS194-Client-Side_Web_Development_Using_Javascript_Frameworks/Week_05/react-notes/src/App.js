import logo from './logo.svg';
import './App.css';
import React from 'react';

function App() {

  // This is a synthetic event
  const handleEvent = event => {
    // console.log(event.target.value);
    setCheckTerm(event.target.value);
  }

  // React States
  const [checkTerm, setCheckTerm] = React.useState("Type something above");

  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <div>
          <label htmlFor="Check">Check: </label>
          <input id="check" type="text" onChange={handleEvent}/>
          <p>{checkTerm}</p>
        </div>
      </header>
    </div>
  );
}

export default App;
