import React, {useState} from 'react';

// ----------------------------------------------------
// DO NOT MODIFY THE APP COMPONENT BELOW 
// ----------------------------------------------------
const App = () => {
  return (
    <div>
      <DisplayParagraph
        text={`Singleness of purpose is one of the chief essentials for success in life, no matter what may be one’s aim.`}
        maxLength={25}
      />
    </div>
  );
};
// ----------------------------------------------------
// DO NOT MODIFY THE APP COMPONENT ABOVE ^^^
// ----------------------------------------------------


function DisplayParagraph({ text, maxLength }) {

  // ----------------------------------------------------
  // TODO (A): fill in YOUR_CODE_HERE below. Create a 
  // state, and initialize it to a boolean value for 
  // toggling the paragraph into either a long or short form.
  // HINT: const [...] = useState(...);
  // ----------------------------------------------------
  const [toggle, setToggle] = useState(false);

  // ----------------------------------------------------
  // TODO (B): fill in YOUR_CODE_HERE below. This is the bulk
  // of the toggling you need to perform
  // ----------------------------------------------------
  return (
    <div>
      {toggle ? text : text.substring(0, maxLength)}
      ...
      <a onClick={ ()=> setToggle( (toggle) => !toggle ) }>{toggle ? "READ LESS" : "READ MORE"}</a>
    </div>
  );
}

export default App;
