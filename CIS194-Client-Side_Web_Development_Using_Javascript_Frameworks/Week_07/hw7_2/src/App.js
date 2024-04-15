import React, { useReducer } from 'react';

const products = [
  {
    emoji: '🍦',
    name: 'ice cream',
    price: 10
  },
  {
    emoji: '🍩',
    name: 'donuts',
    price: 12.5,
  },
  {
    emoji: '🍉',
    name: 'watermelon',
    price: 8
  }
];

// --------------------------------------------
// !!! DO NOT MODIFY ABOVE THIS LINE !!!
// --------------------------------------------

// YOUR MAY ADD ANY ADDITIONAL FUNCTIONS HERE IF YOU NEED, NAMELY THE computeTotal(), etc.


function reducer(state, action) {
  switch(action.type) {
    case "add":
      return [...state, action.product];
    case "remove":
      return state.splice(state.indexOf(action.product), 1)
  }
}

const computeTotal = (state) => {
  let price = 0;

  console.log(state);

  for(let i = 0; i < state.length; i++)
  {
    console.log(state[i].price);
    price += state[i].price;
  }
  return price;
};

const App = () => {

  const [state, dispatch] = useReducer(reducer, []);

  // YOUR CODE HERE
  const add = (product) => {
    dispatch( {type: "add", product} );
  };

  const remove = (product) => {
    // console.log(state);
    // console.log(state.indexOf(product));
    // state.splice(state.indexOf(product), 1)
    // console.log(state);
    // console.log(product)
    if(state.indexOf(product) > -1)
    {
      console.log("In state");
      dispatch( {type: "remove", product} );
    }
    else
    {
      console.log("out of state")
    }
    // dispatch( {type: "remove", product} );
  }

// --------------------------------------------
// !!! DO NOT MODIFY BELOW THIS LINE !!!
// --------------------------------------------
  return(
    <>
      <div>
        Total Items in Shopping Cart: {state.length}
      </div>
      <div>Total Cost: ${computeTotal(state)}</div>

      <div>
        {products.map(product => (
          <div key={product.name}>
            <div className="product">
              <span>{product.emoji}</span>
            </div>
            <div>Price ${product.price}</div>
            <button onClick={() => add(product)}>Add</button>
            <button onClick={() => remove(product)}>Remove</button>
          </div>
        ))}
      </div>
    </>
  )
}
export default App;
