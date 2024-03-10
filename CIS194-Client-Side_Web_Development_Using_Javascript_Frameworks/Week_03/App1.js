import logo from './logo.svg';
import './App.css';

function App() {
  const react = ['NPM', 'Node.js', 'JXS', 'Babel', 'Transpiler', 'Props', 'Single Page Application'];
  
  return (
    <ol>
      {react.map((listItem) => (
        <li>{listItem}</li>
      ))}
    </ol>
  );
}
export default App;
