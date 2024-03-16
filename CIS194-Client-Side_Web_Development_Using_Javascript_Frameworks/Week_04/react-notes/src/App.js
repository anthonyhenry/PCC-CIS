import logo from './logo.svg';
import './App.css';

// List of javascript objects
const projects = [
  {
    name: "Calavera",
    link: "https://anthonyhenry.github.io/100/Projects/Skull/"
  },
  {
    name: "Task Manager",
    link: "https://anthonyhenry.github.io/100/Projects/Pomodoro-Task-Manager/"
  }
];

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <ol>
          {/* Iterate through projects array to show projects as link elements */}
          {projects.map(function(project){
            return <li><a href={project.link} target="_blank">{project.name}</a></li>
          })}
        </ol>
      </header>
    </div>
  );
}

export default App;
