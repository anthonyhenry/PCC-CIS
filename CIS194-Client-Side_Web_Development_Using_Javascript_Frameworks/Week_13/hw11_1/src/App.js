import React, {useState} from 'react';

function App() {

  const handleEvent = event => {
    setPhoneNumber(event.target.value);
  }

  const [phoneNumber, setPhoneNumber] = useState("");

  const [error, setError] = useState("");

  const validatePhoneNumber = evt => {
    if(/\(?(\d{3})\)?[-\s]?(\d{3})[-\s]?(\d{4})/.test(phoneNumber))
    {
      setError(true);
    }
    else
    {
      setError(false);
    }
  }

  return (
    <div>
      <h1>Phone Number Entered: {phoneNumber}</h1>
      <p>Phone Number:</p>
      <input onChange={handleEvent}/>
      <br/>
      { error ? "Valid" : "Invalid" }<br/>
      <button onClick={validatePhoneNumber}>Validate</button>
    </div>
  );
}

export default App;
