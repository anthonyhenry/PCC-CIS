import React from "react"

export default function Card(props) {
  const imgSrc = "images/" + props.img;
  return (
    <div>
        <img src={imgSrc}/>
        <p>{props.title}</p>
        <p><strong>Average cost ${props.cost}</strong> / LB</p>
        <p>Kingdom: {props.kingdom}</p>
        <p>Family: {props.family}</p>
        <p>Genus: {props.genus}</p>
        <p>Origin: {props.origin}</p>
    </div>
  );
}