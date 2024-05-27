import React, {useState} from 'react';
import Login from '../Login'
import LandingPage from '../Landing'
import {BrowserRouter, Route, Routes} from 'react-router-dom';
import Navigation from '../Navigation';
import * as ROUTES from "../constants/paths"

function App()
{
    const [token, setToken] = useState();

    if(!token)
    {
        return <Login setToken={setToken}/>   
    }

    return(
        <>
            <h1>App</h1>
            <BrowserRouter>
                <Navigation/>
                <Routes>
                    <Route path={ROUTES.LOGIN} element={<Login/>} />
                    <Route path={ROUTES.LANDING} element={<LandingPage/>} />
                </Routes>
            </BrowserRouter>
        </>
    );
}

export default App;