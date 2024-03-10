import logo from './logo.svg';
import './App.css';

import { createElement } from 'react';

function App() {
  const react = ['NPM', 'Node.js', 'JXS', 'Babel', 'Transpiler', 'Props', 'Single Page Application'];
  
  return (
    <ol>
      {react.map((listItem) => (
        createElement(
          'li',
          null,
          listItem
        )
      ))}
    </ol>
  );
}

export default App;