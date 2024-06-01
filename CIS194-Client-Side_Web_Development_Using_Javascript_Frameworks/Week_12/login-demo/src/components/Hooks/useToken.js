import { useState } from "react";

function useToken()
{
    const getToken = () => {
        const tokenItem = sessionStorage.getItem('token');
        const userToken = JSON.parse(tokenItem);
        return userToken?.token;
    }

    const [token, setToken] = useState(getToken());

    const saveToken = (userToken) => {
        sessionStorage.setItem('token', JSON.stringify(userToken));
        setToken(userToken.token);
    };
    return {
        token,
        setToken: saveToken
    }
}

export default useToken;