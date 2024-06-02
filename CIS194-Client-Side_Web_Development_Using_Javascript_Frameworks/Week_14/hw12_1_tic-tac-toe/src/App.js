// https://react.dev/learn/tutorial-tic-tac-toe#stylescss
import { useState } from "react";

// Components must start with a capital letter
function Square()
{
  const [value, setValue] = useState(null);

  function handleClick()
  {
    setValue('X');
  }

  return (
    <button 
      className="square"
      onClick={handleClick}
    >
      {value}
    </button>
  )
}

// The export JavaScript keyword makes this function accessible outside of this file
// The default keyword tells other files using your code that it’s the main function in your file
export default function Board() {
  return (
    <>
      <div className="board-row">
        <Square />
        <Square />
        <Square />
      </div>
      <div className="board-row">
        <Square />
        <Square />
        <Square />
      </div>
      <div className="board-row">
        <Square />
        <Square />
        <Square />
      </div>
    </>
  )
}
