const validate = require('validator')
var email = "angadbhalla@mail.com"
console.log(validate.isEmail(email))
var name = "Angad"
console.log(validate.isLowercase(name))
var empty = "hello"
console.log(validate.isEmpty(empty))