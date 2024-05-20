function Name(props)
{
    return <h1>{props.name}</h1>
}

function Title(props)
{
    return <p>{props.title}</p>
}

function Email(props)
{
    return <p>{props.email}</p>
}

function Phone(props)
{
    return <p>{props.phone}</p>
}

export default function BusinessCard(props)
{
    return(
        <div className={props.darkMode ? "dark" : "light"}>
            <Name name="Anthony"/>
            <Title title="Game Designer"/>
            <Email email="anthonyh1497@gmail.com"/>
            <Phone phone="805-232-6299"/>
        </div>
    )
}