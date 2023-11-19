window.addEventListener("DOMContentLoaded", domLoaded);

function domLoaded()
{
   // Constant variables for the input fields
   const celsiusInputElement =  document.querySelector("#cInput");
   const fahrenheitInputElement = document.querySelector("#fInput");

   // Make sure only one text field can be modified at a time
   celsiusInputElement.addEventListener("input", () => clearTemperatureField(fahrenheitInputElement));
   fahrenheitInputElement.addEventListener("input", () => clearTemperatureField(celsiusInputElement));

   // Grab the convert button
   const convertBtn = document.querySelector("#convertButton");
   // Add a click event listener to the convert button
   convertBtn.addEventListener("click", function(){
      // Clear the error message if it isn't currently empty
      const errorMsg = document.querySelector("#errorMessage");
      if(errorMsg.innerHTML != "")
      {
         errorMsg.innerHTML = "";
      }

      // Check if the celsius field has been filled properly
      if(isNaN(celsiusInputElement.value) == false && celsiusInputElement.value != "")
      {
         fahrenheitInputElement.value = convertCtoF(celsiusInputElement.value);
      }
      // Check if the fahrenheight field has been filled properly
      else if(isNaN(fahrenheitInputElement.value) == false && fahrenheitInputElement.value != "")
      {
         celsiusInputElement.value = convertFtoC(fahrenheitInputElement.value);
      }
      // Inputs not valid
      else
      {
         // Find out which input is bad
         let offendingInput;
         if(fahrenheitInputElement.value != "")
         {
            offendingInput = fahrenheitInputElement.value;
         }
         else
         {
            offendingInput = celsiusInputElement.value;
         }

         // Let the user know the input was bad
         errorMsg.innerHTML = offendingInput + " is not a number";
      }

      // Update weather image
      if(isNaN(fahrenheitInputElement.value) == false && fahrenheitInputElement.value != "")
      {
         // Constant variables for fahrenheit temperature and img element
         const fahrenheitTemperature = fahrenheitInputElement.value;
         const img = document.querySelector("#weatherImage");

         // Update the image appropriately
         if(fahrenheitTemperature <= 32)
         {
            img.src = "cold.png";
         }
         else if(fahrenheitTemperature <= 50)
         {
            img.src = "cool.png";
         }
         else
         {
            img.src = "warm.png";
         }
      }
   });
}

// Function to clear temperature field that is not being updated
function clearTemperatureField(temperatureFieldToClear)
{
   if(temperatureFieldToClear.value != "")
   {
      temperatureFieldToClear.value = "";
   }
}

function convertCtoF(degreesCelsius)
{
   return degreesCelsius * 9/5 + 32;
}

function convertFtoC(degreesFahrenheit)
{
   return (degreesFahrenheit - 32) * 5/9;
}