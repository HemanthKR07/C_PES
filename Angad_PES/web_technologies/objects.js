var employee = {
    firstname: "John",
    lastname: "Doe",
    age: 30,
    designation: "Developer",
    fullname: function(){
        return this.firstname + " " + this.lastname;
    }
};


console.log(employee.firstname);
console.log(employee.age);
console.log(employee.fullname());

function func(){
    var x = document.getElementsByClassName("div1");
    x[0].innerHTML = "Hello World!";
}