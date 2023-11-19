function parseScores(scoresString)
{
   // Turn the scores into an array of scores
   return scoresString.split(" ");
}

function buildDistributionArray(scoresArray)
{
   // Create distribution array
   let distributionArray = [0, 0, 0, 0, 0];

   // Loop through scores and increment appropriate element in array
   for(score of scoresArray)
   {
      if(score >= 90)
      {
         distributionArray[0]++;
      }
      else if(score >= 80)
      {
         distributionArray[1]++;
      }
      else if(score >= 70)
      {
         distributionArray[2]++;
      }
      else if(score >= 60)
      {
         distributionArray[3]++;
      }
      else
      {
         distributionArray[4]++;
      }
   }

   // Return the array
   return distributionArray;
}

function setTableContent(userInput) {
   // Parse scores
   let scores = parseScores(userInput);
   // Build distribution array
   let gradeDistribution = buildDistributionArray(scores);

   // For loop to create new elements, fill data, and add to DOM
   for(let i = 0; i < gradeDistribution.length; i++)
   {
      // Create first row elements
      let firstRowTd = document.createElement("td");
      let firstRowTdDiv = document.createElement("div");

      // Add styling to first row div
      firstRowTdDiv.style.height = (gradeDistribution[i] * 10) + "px";
      firstRowTdDiv.classList.add("bar" + i);

      // Add first row elements to DOM
      firstRowTd.appendChild(firstRowTdDiv);
      document.querySelector("#firstRow").appendChild(firstRowTd);

      // Create third row element
      let thirdRowTd = document.createElement("td");
      // Fill the third row element with the correspoding grade distribution
      thirdRowTd.innerText = gradeDistribution[i];
      
      // Add the row element to the DOM
      document.querySelector("#thirdRow").appendChild(thirdRowTd);
   }
}

// The argument can be changed for testing purposes
setTableContent("45 78 98 83 86 99 90 59");