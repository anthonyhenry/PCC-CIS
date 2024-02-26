function isStrongPassword(password)
{
    // Make sure the password is at least 8 characters long
    if(password.length < 8)
    {
        return false;
    }
    // Make sure the password does not contain the string "password"
    else if(password.indexOf("password") != -1)
    {
        return false;
    }
    // Make sure the password contains at least one upper case character
    else if(password.toLowerCase() == password)
    {
        return false;
    }
    else
    {
        return true;
    }
}