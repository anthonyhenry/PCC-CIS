// Components must start with a capital letter
function Square( {value} )
{
  return <button className="square">{value}</button>; 
}

// The export JavaScript keyword makes this function accessible outside of this file
// The default keyword tells other files using your code that it’s the main function in your file
export default function Board() {
  return (
    <>
      <div className="board-row">
        <Square value="X"/>
        <Square value="X"/>
        <Square value="X"/>
      </div>
      <div className="board-row">
        <Square value="X"/>
        <Square value="X"/>
        <Square value="X"/>
      </div>
      <div className="board-row">
        <Square value="X"/>
        <Square value="X"/>
        <Square value="X"/>
      </div>
    </>
  )
}
