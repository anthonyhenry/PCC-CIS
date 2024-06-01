import React, {useState} from 'react';

function App() {

  const handleEvent = event => {
    setPhoneNumber(event.target.value);
  }

  const [phoneNumber, setPhoneNumber] = useState("");

  const [error, setError] = useState("");

  const validatePhoneNumber = evt => {
    if(/\(?(\d{3})\)?[-\s]?(\d{3})[-\s]?(\d{4})\b/.test(phoneNumber))
    {
      setError("Valid Phone Number");
    }
    else
    {
      setError("Invalid Phone Number");
    }
  }

  return (
    <div>
      <h1>Phone Number Entered: {phoneNumber}</h1>
      <p>Phone Number:</p>
      <input onChange={handleEvent}/>
      <br/>
      {error}
      {error ? <br/> : ""}
      <button onClick={validatePhoneNumber}>Validate</button>
    </div>
  );
}

export default App;
