import logo from './logo.svg';
import './App.css';
import React from 'react';

const useMyCustomHook = (key, initialState) => {
  // State Hook
  const [value, setValue] = React.useState(
    localStorage.getItem(key) || initialState
  );

  React.useEffect(
    ()=> {
      localStorage.setItem(key, value);
    },
    [key, value]
  );

  return [value, setValue]
}

const App = () => {
  // Your "key" is 'React'
  // Your "initialState" is 'Redux'
  const [checkTerm, setCheckTerm] = useMyCustomHook(
    'React',
    'Redux'
  );
};

export default App;