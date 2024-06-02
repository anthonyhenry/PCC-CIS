// https://react.dev/learn/tutorial-tic-tac-toe#stylescss
import { useState } from "react";

// Components must start with a capital letter
function Square( {value, onSquareClick} )
{
  return (
    <button className="square" onClick={onSquareClick}>
      {value}
    </button>
  )
}

function calculateWinner(squares)
{
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
  ];

  for (let i = 0; i < lines.length; i++)
  {
    const [a, b, c] = lines[i];
    
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c])
    {
      return squares[a];
    }
  }

  return null;
}


// The export JavaScript keyword makes this function accessible outside of this file
// The default keyword tells other files using your code that it’s the main function in your file
export default function Board() {
  
  // State that keeps track of whoese turn
  const [xIsNext, setXIsNext] = useState(true);

  const [squares, setSquares] = useState(Array(9).fill(null)); // Creates an array with nine elements and sets each of them to null
  
  function handleClick(i)
  {
    // Return early if the square clicked is not empty or if someone has won
    if(squares[i] || calculateWinner(squares))
    {
      return;
    }

    // Duplicate squares array
    const nextSquares = squares.slice();

    // Add X or O to the duplicate array
    if(xIsNext)
    {
      nextSquares[i] = "X";
    }
    else
    {
      nextSquares[i] = "O";
    }

    // Update squares array
    setSquares(nextSquares);
    
    // Change whose turn
    setXIsNext(!xIsNext);
  }

  const winner = calculateWinner(squares);
  let status;
  if(winner)
  {
    status = "Winner: " + winner;
  }
  else
  {
    status = "Next player: " + (xIsNext ? "X" : "O");
  }

  return (
    <>
      <div className="status">
        {status}
      </div>

      <div className="board-row">
        <Square value={squares[0]} onSquareClick={ () => handleClick(0)} />
        <Square value={squares[1]} onSquareClick={ () => handleClick(1)} />
        <Square value={squares[2]} onSquareClick={ () => handleClick(2)} />
      </div>
      <div className="board-row">
        <Square value={squares[3]} onSquareClick={ () => handleClick(3)} />
        <Square value={squares[4]} onSquareClick={ () => handleClick(4)} />
        <Square value={squares[5]} onSquareClick={ () => handleClick(5)} />
      </div>
      <div className="board-row">
        <Square value={squares[6]} onSquareClick={ () => handleClick(6)} />
        <Square value={squares[7]} onSquareClick={ () => handleClick(7)} />
        <Square value={squares[8]} onSquareClick={ () => handleClick(8)} />
      </div>
    </>
  )
}
