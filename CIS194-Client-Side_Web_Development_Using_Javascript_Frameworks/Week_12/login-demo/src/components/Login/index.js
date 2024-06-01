import React, { useState } from 'react';

async function fetchToken(creds) 
{
    return fetch("http://localhost:8080/login", {
        method: "POST",
        header: {
        "Content-Type": "applicatioin/json",
        },
        body: JSON.stringify(creds),
    }).then((data) => data.json());
}

function Login( {setToken} )
{
    const [username, setUserName] =useState();
    const [password, setPassword] = useState();
    const [error, setError] = useState(false);

    const handleSubmit = async evt => {
        evt.preventDefault();
        const token = await fetchToken({
            username, 
            password,
        });
        setToken(token);
    }

    const validateChar = evt => {
        if(/\*/.test(username))
        {
            setError(true);
            return;
        }
        setError(false);
    }

    return(
        <div className='login-wrapper'>
            <h1>Please login</h1>
            <form onSubmit={handleSubmit}>
                <label>
                    <p>Username</p>
                    <input 
                        type='text' 
                        onChange={evt=>setUserName(evt.target.value)}
                        onFocus={()=>setError(true)}
                        onBlur={()=>setError(false)}
                    />
                </label>
                {error && 
                    <div>
                        <span>✅: All alphanumeric characters</span>
                        <br/>
                        <span>⛔: *</span>
                    </div>}
                <label>
                    <p>Password</p>
                    <input 
                        type='password'
                        onChange={evt=>setPassword(evt.target.value)}
                    />
                </label>
                <div>
                    <button type='submit' onClick={validateChar}>Submit</button>
                </div>
            </form>
        </div>
    );
}

export default Login;