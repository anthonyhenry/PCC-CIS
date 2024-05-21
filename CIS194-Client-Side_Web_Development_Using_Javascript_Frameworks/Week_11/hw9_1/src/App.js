import './App.css';
import {useState} from 'react';
import ToggleSelector from './ToggleSelector';
import Info from './components/Info';
import About from './components/About';
import Funfacts from './components/Funfacts';
import Contact from './components/Contact';

function App() {

  const [darkMode, setDarkMode] = useState();

  function toggleDarkMode()
  {
    setDarkMode(mode=>!mode);
  }


  return (
    <div id='card' className={darkMode ? "dark" : "light"}>
      <ToggleSelector
        darkMode={darkMode}
        toggleDarkMode={toggleDarkMode}
      />
      <Info
        darkMode={darkMode}
        toggleDarkMode={toggleDarkMode}
      />
      <About/>
      <Funfacts/>
      <Contact/>
    </div>
  );
}

export default App;
