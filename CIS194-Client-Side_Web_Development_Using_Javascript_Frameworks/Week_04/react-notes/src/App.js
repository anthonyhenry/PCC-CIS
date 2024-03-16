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

// Each function below is a React component

// The App component is the entry point and responsible for rendering stuff
function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <ol>
          {/* This is how you call a component*/}
          <List_Projects/> 
        </ol>
      </header>
    </div>
  );
}

// Create a component to display items from the project array
function List_Projects()
{
  // Iterate through projects array to show projects as link elements
  return projects.map(project => // Arrow function
    <li><a href={project.link} target="_blank">{project.name}</a></li>
  )
  
  // This is how you do the above without an arrow function
  // return projects.map(function(project){
  //   return <li><a href={project.link} target="_blank">{project.name}</a></li>
  // })
}

export default App;
