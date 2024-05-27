import React from 'react';
import { useParams } from 'react-router-dom';
import notes from '../assets/data';

const NotePage = () => {
    let noteId = useParams();
    console.log(noteId)

    let note = notes.find(note => note.id === Number(noteId.id))

    return (
        <div>
            <p>{note?.body}</p>
        </div>
    )
}

export default NotePage
