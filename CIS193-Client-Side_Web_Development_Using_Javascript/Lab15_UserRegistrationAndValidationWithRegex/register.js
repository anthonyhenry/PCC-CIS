function checkForm() {
   // Reset and hide the form errors div
   const errorsDiv = document.querySelector("#formErrors");
   errorsDiv.innerHTML = "";
   errorsDiv.classList.add("hide");
   // document.querySelector("#formErrors").innerHTML = "";
   // document.querySelector("#formErrors").classList.add("hide");

   // Ensure a full name with a length greater than or equal to 1 was provided
   const name = document.querySelector("#fullName");
   if(name.value.length < 1)
   {
      createErrorMessage("Missing full name.", name);
   }
   else
   {
      removeErrorClass(name); // Remove error class if the input is valid
   }

   // Ensure that a valid email address was provided
   const email = document.querySelector("#email");
   const emailRegEx = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,5}$/;
   const test = emailRegEx.test(email);
   if(emailRegEx.test(email.value) == false)
   {
      createErrorMessage("Invalid or missing email address.", email);
   }
   else
   {
      removeErrorClass(email); // Remove error class if the input is valid
   }

   const password = document.querySelector("#password");
   let validPassword = true; // Boolean variable for tracking if the password is valid
   // Ensure the password has 10 to 20 characters
   if(password.value.length < 10 || password.value.length > 20)
   {
      createErrorMessage("Password must be between 10 and 20 characters.", password);
      validPassword = false;
   }
   // Ensure the password contains at least one lowercase character
   const passwordLowerCaseLetterCheck = /[a-z]/;
   if(passwordLowerCaseLetterCheck.test(password.value) == false)
   {
      createErrorMessage("Password must contain at least one lowercase character.", password);
      validPassword = false;
   }
   // Ensure the password contains at least one uppercase character
   const passwordUpperCaseLetterCheck = /[A-Z]/;
   if(passwordUpperCaseLetterCheck.test(password.value) == false)
   {
      createErrorMessage("Password must contain at least one uppercase character.", password);
      validPassword = false;
   }
   // Ensure the password contains at least one digit
   const passwordDigitCheck = /\d/;
   if(passwordDigitCheck.test(password.value) == false)
   {
      createErrorMessage("Password must contain at least one digit.", password);
      validPassword = false;
   }

   // Check if the password passed all tests
   if(validPassword == true)
   {
      removeErrorClass(password); // Remove error class if the input is valid
   }

   // Ensure the password and confirmation password match
   const confirmationPassword = document.querySelector("#passwordConfirm");
   if(confirmationPassword.value != password.value)
   {
      createErrorMessage("Password and confirmation password don't match.", confirmationPassword);
   }
   else
   {
      removeErrorClass(confirmationPassword); // Remove error class if the input is valid
   }

   // Display error messages if there are any
   if(errorMessages.length > 0)
   {
      // Create an unordered list element
      const errorsList = document.createElement("ul");

      // Loop through the error messages array to add all list items to the unorderd list
      for(message of errorMessages)
      {
         errorsList.appendChild(message);
      }
      
      // let errorsDiv = document.querySelector("#formErrors");
      errorsDiv.appendChild(errorsList);
      errorsDiv.classList.remove("hide");

      // Clear the error messages array
      errorMessages = [];
   }
}

// Create an empty array for holding error messages
let errorMessages = [];
// Function for creating error messages
function createErrorMessage(errorMessage, errorField)
{
   // Create a list item element
   const errorLi = document.createElement("li");
   // Fill the list item with the error message
   errorLi.innerText = errorMessage;
   // Add the error message element to the error messages array
   errorMessages.push(errorLi);

   // Add the error class to the field with the error
   errorField.classList.add("error");
}

function removeErrorClass(formField)
{
   formField.classList.remove("error");
}

document.getElementById("submit").addEventListener("click", function(event) {
   checkForm();
   

   // Prevent default form action. DO NOT REMOVE THIS LINE
   event.preventDefault();
});