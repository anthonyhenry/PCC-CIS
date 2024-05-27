import React from 'react'
import notes from '../assets/data'
import ListItem from '../components/ListItem'

const NotesListPage = () => {
  return (
    <div>
      <div>
        <div className='notes-list'>
            {notes.map(note => (
                <ListItem note={note}/>
            ))}
        </div>
      </div>
    </div>
  )
}

export default NotesListPage
