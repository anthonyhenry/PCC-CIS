class SuperHuman {
	constructor(name, powerLevel) {
		this.name = name;
		this.powerLevel = powerLevel;
	}
}

// Define SuperHero and SuperVillain classes here
class SuperHero extends SuperHuman
{
	// 
	constructor(name, alias, powerLevel)
	{
		super(name, powerLevel); // Constructor calls parent class constructor with given name and powerLevel
		this.alias = alias;
	}

	// Battle method that has a SuperVillain parameter
	battle(SuperVillain)
	{
		// Return true if the hero's powerLevel is >= the villain's powerLevel, false otherwise.
		if(this.powerLevel >= SuperVillain.powerLevel)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

class SuperVillain extends SuperHuman
{
	constructor(name, alias, powerLevel)
	{
		super(name, powerLevel); // Constructor calls parent class constructor with given name and powerLevel
		this.alias = alias;
	}

	// SuperVillain method that returns the string "Ha ha ha!".
	getEvilChuckle()
	{
		return "Ha ha ha!"
	}
}


const heroes = {
	"Super Bacon": new SuperHero("Jack Oinker", "Super Bacon", 2),
	"Flat-Man": new SuperHero("Peter Pranker", "Flat-Man", 5),
	"Mighty Woman": new SuperHero("Diana Dense", "Mighty Woman", 8),
	"Captain Marvelous": new SuperHero("Carol Hangers", "Captain Marvelous", 9)
};

const villains = {
	"The Jokester": new SuperVillain("Jack Nastier", "The Jokester", 3),
	"Magnet Man": new SuperVillain("Max Eisenhardt", "Magnet Man", 6),
	"Lex Loner": new SuperVillain("Lex Loner", "Lex Loner", 2),
	"Thankos": new SuperVillain("Thankos", "Thankos", 9)
};

registerHandlers();

function registerHandlers() {
	// Detect selection of hero and villain
	document.querySelector("#heroSelect").addEventListener("change", selectionChanged);
	document.querySelector("#villainSelect").addEventListener("change", selectionChanged);

	selectionChanged();
}

function selectionChanged() {
	const selectedHeroValue = document.querySelector("#heroSelect").value;
	const selectedVillainValue = document.querySelector("#villainSelect").value;

	// Get hero and villain selected
	const selectedHero = heroes[selectedHeroValue];
	const selectedVillain = villains[selectedVillainValue];

	// Call the selected hero's battle method, passing in the selected villain. Display the battle winner's alias in the winner paragraph.
	const winner = selectedHero.battle(selectedVillain);
	const winnerParagraph = document.querySelector("#winner");
	if(winner == true)
	{
		winnerParagraph.innerText = "Winner: " + selectedHero.alias + "!";
	}
	else
	{
		winnerParagraph.innerText = "Winner: " + selectedVillain.alias + "!";
	}
}
