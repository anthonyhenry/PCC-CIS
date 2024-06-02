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

function Board( {xIsNext, squares, onPlay} ) {
  
  function handleClick(i)
  {
    // Return early if the square clicked is not empty or if someone has won
    if(squares[i] || calculateWinner(squares))
    {
      return;
    }

    // Duplicate squares array
    const nextSquares = squares.slice();

    if (xIsNext)
    {
      nextSquares[i] = 'X';
    } 
    else 
    {
      nextSquares[i] = 'O';
    }

    onPlay(nextSquares);
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

// The export JavaScript keyword makes this function accessible outside of this file
// The default keyword tells other files using your code that it’s the main function in your file
export default function Game()
{
  // History array
  const [history, setHistory] = useState([Array(9).fill(null)]);

  // Variable to keep track of which step the user is currently viewing
  const [currentMove, setCurrentMove] = useState(0);

  // Keeps track of whoese turn
  const xIsNext = currentMove % 2 === 0;

  // Current state of board is the last squares array from history
  const currentSquares = history[currentMove];

  function handlePlay(nextSquares)
  {
    const nextHistory = [...history.slice(0, currentMove + 1), nextSquares];
    setHistory(nextHistory);
    setCurrentMove(nextHistory.length - 1);
  }

  function jumpTo(nextMove)
  {
    setCurrentMove(nextMove);
  }

  // State for toggle button
  const [isToggled, setToggle] = useState(true);

  // Function for when the toggle is pressed
  function handleToggle()
  {
    // Switch toggle
    setToggle(!isToggled);
  }

  const moves = history.map( (squares, move) => {
    let description;
    
    if(move > 0)
    {
      description = "Go to move #" + move;
    }
    else
    {
      description = "Go to game start";
    }
    
    return(
      <li key={move}>
        <button onClick={() => jumpTo(move)}>{description}</button>
      </li>
    )
  })

  const displayedMoves = isToggled ? moves : [...moves].reverse();

  return(
    <div className="game">
      <div className="game-board">
        <Board xIsNext={xIsNext} squares={currentSquares} onPlay={handlePlay}/>
      </div>
      <div className="game-info">
        <button onClick={handleToggle}>
          {isToggled ? 'Ascending Order: On' : 'Ascending Order: Off'}
        </button>
        <ol>{displayedMoves}</ol>
      </div>
    </div>
  );
}