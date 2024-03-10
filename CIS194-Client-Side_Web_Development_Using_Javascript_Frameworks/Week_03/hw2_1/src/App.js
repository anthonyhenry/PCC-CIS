import logo from './logo.svg';
import './App.css';

import { createElement } from 'react';

function App() {
  const react = ['NPM', 'Node.js', 'JXS', 'Babel', 'Transpiler', 'Props', 'Single Page Application'];
  
  return (
    // These two bits of code do the exact same thing.

    // This one uses JSX
    <ol>
      {react.map((listItem) => (
        <li>{listItem}</li>
      ))}
    </ol>
    
    // This one uses React.createElement
    // <ol>
    //   {react.map((listItem) => (
    //     createElement(
    //       'li',
    //       null,
    //       listItem
    //     )
    //   ))}
    // </ol>
  );
}

export default App;