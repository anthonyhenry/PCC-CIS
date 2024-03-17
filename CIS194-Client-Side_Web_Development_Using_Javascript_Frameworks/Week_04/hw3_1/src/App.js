import './App.css';
import data from "./data"
import Card from "./Card"

function App() {
 
    // YOUR CODE HERE
    return (
        data.map(function(fruit){
            return <Card img={fruit.coverImg} title={fruit.title} cost={fruit.price} kingdom={fruit.stats.kingdom} family={fruit.stats.family} genus={fruit.stats.genus} origin={fruit.location}/>
        })
    );
}

export default App;
