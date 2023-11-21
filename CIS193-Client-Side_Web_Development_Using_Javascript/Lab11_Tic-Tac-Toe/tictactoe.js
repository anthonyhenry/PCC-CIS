let playerTurn = true;
let computerMoveTimeout = 0;

const gameStatus = {
	MORE_MOVES_LEFT: 1,
	HUMAN_WINS: 2,
	COMPUTER_WINS: 3,
	DRAW_GAME: 4
};

window.addEventListener("DOMContentLoaded", domLoaded);

function domLoaded() {
	// Setup the click event for the "New game" button
	const newBtn = document.getElementById("newGameButton");
	newBtn.addEventListener("click", newGame);

	// Create click-event handlers for each game board button
	const buttons = getGameBoardButtons();
	for (let button of buttons) {
		button.addEventListener("click", function () { boardButtonClicked(button); });
	}

	// Clear the board
	newGame();
}

// Returns an array of 9 <button> elements that make up the game board. The first 3 
// elements are the top row, the next 3 the middle row, and the last 3 the 
// bottom row. 
function getGameBoardButtons() {
	return document.querySelectorAll("#gameBoard > button");
}

function checkForWinner() {
	
	const buttons = getGameBoardButtons();

	// Ways to win
	const possibilities = [
		[0, 1, 2], [3, 4, 5], [6, 7, 8], // rows
		[0, 3, 6], [1, 4, 7], [2, 5, 8], // columns
		[0, 4, 8], [2, 4, 6] // diagonals
	];

	// Check for a winner first
	for (let indices of possibilities) {
		if (buttons[indices[0]].innerHTML !== "" &&
			buttons[indices[0]].innerHTML === buttons[indices[1]].innerHTML &&
			buttons[indices[1]].innerHTML === buttons[indices[2]].innerHTML) {
			
			// Found a winner
			if (buttons[indices[0]].innerHTML === "X") {
				return gameStatus.HUMAN_WINS;
			}
			else {
				return gameStatus.COMPUTER_WINS;
			}
		}
	}

	// See if any more moves are left
	for (let button of buttons) {
		if (button.innerHTML !== "X" && button.innerHTML !== "O") {
			return gameStatus.MORE_MOVES_LEFT;
		}
	}

	// If no winner and no moves left, then it's a draw
	return gameStatus.DRAW_GAME;
}

function newGame() 
{
	// Cancel the computer's move timer
	clearTimeout(computerMoveTimeout);
	computerMoveTimeout = 0;

	// Reset all buttons
	const buttons = getGameBoardButtons();
	for(let button of buttons)
	{
		button.innerHTML = "";
		button.disabled = false;
		button.classList.remove("x");
		button.classList.remove("o");
	}

	// Player goes first
	playerTurn = true;
	document.querySelector("#turnInfo").innerText = "Your turn";
}

// Place a red X in buttons the player selects on their turn
function boardButtonClicked(button) 
{
	if(playerTurn == true)
	{
		button.classList.add("x");
		button.innerText = "X";
		button.disabled = true;
		switchTurn();
	}
}

function switchTurn() {	
	// No winner yet
	if(checkForWinner() == 1)
	{
		// Switch to computer's turn
		if(playerTurn == true)
		{
			playerTurn = false;
			document.querySelector("#turnInfo").innerText = "Computer's turn";
			computerMoveTimeout = setTimeout(makeComputerMove, 1000);
		}
		// Switch to player's turn
		else
		{
			playerTurn = true;
			document.querySelector("#turnInfo").innerText = "Your turn";
		}
	}
	// Game Over
	else
	{
		playerTurn = false;
		
		// Human wins
		if(checkForWinner() == 2)
		{
			document.querySelector("#turnInfo").innerText = "You win!";
		}
		// Computer wins
		else if (checkForWinner() == 3)
		{
			document.querySelector("#turnInfo").innerText = "Computer wins!";
		}
		// Draw
		else
		{
			document.querySelector("#turnInfo").innerText = "Draw game";
		}
	}
}

function makeComputerMove() {
	// Turn available buttons into an array
	let availableButtons = Array.from(getGameBoardButtons());
	// Remove buttons that are not empty from the array
	for(let i = availableButtons.length - 1; i >= 0; i--)
	{
		if(availableButtons[i].innerText != "")
		{
			availableButtons.splice(i, 1);
		}
	}

	// Select a random button from the array for the computer to play in
	let computerChoice = Math.floor(Math.random() * availableButtons.length);
	computerChoice = availableButtons[computerChoice];
	// Place an O in the button
	computerChoice.classList.add("o");
	computerChoice.innerText = "O";
	computerChoice.disabled = true;
	// Change turns
	switchTurn();
}