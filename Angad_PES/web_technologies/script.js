function submitForm(event) {
    event.preventDefault();
    var name = document.getElementById("name").value;
    alert("Thank you for your feedback, " + name + "!");
}
var states = ["Andhra Pradesh", "Arunachal Pradesh", "Assam", "Bihar", "Chhattisgarh", "Goa", "Gujarat", "Haryana", "Himachal Pradesh", "Jharkhand", "Karnataka", "Kerala", "Madhya Pradesh", "Maharashtra", "Manipur", "Meghalaya", "Mizoram", "Nagaland", "Odisha", "Punjab", "Rajasthan", "Sikkim", "Tamil Nadu", "Telangana", "Tripura", "Uttar Pradesh", "Uttarakhand", "West Bengal", "Andaman and Nicobar Islands", "Chandigarh", "Dadra and Nagar Haveli and Daman and Diu", "Delhi", "Lakshadweep", "Puducherry"];
var selectElement = document.getElementById("state");
if (selectElement) {
    for (var i = 0; i < states.length; i++) {
        var option = document.createElement("option");
        option.value = states[i];
        option.text = states[i];
        selectElement.appendChild(option);
    }
} else {
    console.error("Element with id 'state' not found.");
}