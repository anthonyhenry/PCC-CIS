import React from 'react';

const App = () => {

  const toc = [
    {
      title: 'React Homepage',
      url: 'https://reactjs.org/',
    },
    {
      title: 'Getting Started',
      url: 'https://reactjs.org/docs/getting-started.html',
    },
    {
      title: 'Hello World',
      url: 'https://reactjs.org/docs/hello-world.html',
    },
    {
      title: 'Introducing JSX',
      url: 'https://reactjs.org/docs/introducing-jsx.html',
    },
    {
      title: 'Rendering Elements',
      url: 'https://reactjs.org/docs/rendering-elements.html',
    }
  ];

  return (
    <div>
      <h1>React: A JavaScript library</h1>

      <Search />

      <hr />

      <List results = {toc}/>
    </div>
  );
};

const Search = props => (
  <div>
    <label htmlFor="search">Search: </label>
    <input type="text" />
  </div>
);

const List = props =>
  props.results.map(item => (
    <div>
      <p>
        <a href={item.url}>{item.title}</a>
      </p>
    </div>
  ));


export default App;