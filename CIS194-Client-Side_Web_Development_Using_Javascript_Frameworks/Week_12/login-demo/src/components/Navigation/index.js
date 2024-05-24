import React from 'react';
import { Link } from "react-router-dom";
import * as ROUTES from "../constants/paths"

function Navigation()
{
    return(
        <>
            <ul>
                <li>
                    <Link to={ROUTES.APP}>App</Link>
                </li>
                <li>
                    <Link to={ROUTES.LOGIN}>Login</Link>
                </li>
                <li>
                    <Link to={ROUTES.LANDING}>Landing Page</Link>
                </li>
            </ul>
        </>
    );
}

export default Navigation;