import React from 'react';

// This is your callback from Search input. You will
// take the event and print its value to the console 
// log
const handleSearch = event =>{
  console.log(event.target.value);
}

const App = () => {
  return (
    <div>
      <h1>React: A JavaScript library</h1>

      <Search onSearch={handleSearch} />

    </div>
  );
};

const Search = props => (
  <div>
    <label htmlFor="search">Search: </label>
    <input id="search" type="text" onChange={props.onSearch}/>
  </div>
);

export default App;