import {ReactComponent as Photo} from '../photo.svg';

export default function Info(props)
{
    return(
        <div id='info'>
            <Photo/>
            <h2>Anthony Hernandez</h2>
            <h3 className={props.darkMode ? "dark" : ""}>Game Designer</h3>
        </div>
    );
}