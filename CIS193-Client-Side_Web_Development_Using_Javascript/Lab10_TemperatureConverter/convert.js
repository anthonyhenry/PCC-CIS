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
   // Add a click event listener
   convertBtn.addEventListener("click", function(){
      const errorMsg = document.querySelector("#errorMessage");
      if(errorMsg.innerHTML != "")
      {
         errorMsg.innerHTML = "";
      }

      // Check if the celsius field has been filled
      if(isNaN(celsiusInputElement.value) == false && celsiusInputElement.value != "")
      {
         fahrenheitInputElement.value = convertCtoF(celsiusInputElement.value);
      }
      else if(isNaN(fahrenheitInputElement.value) == false && fahrenheitInputElement.value != "")
      {
         celsiusInputElement.value = convertFtoC(fahrenheitInputElement.value);
      }
      else
      {
         let offendingInput;
         if(fahrenheitInputElement.value != "")
         {
            offendingInput = fahrenheitInputElement.value;
         }
         else
         {
            offendingInput = celsiusInputElement.value;
         }
         errorMsg.innerHTML = offendingInput + " is not a number";
      }

      if(isNaN(fahrenheitInputElement.value) == false && fahrenheitInputElement.value != "")
      {
         const fahrenheitTemperature = fahrenheitInputElement.value;
         const img = document.querySelector("#weatherImage");

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