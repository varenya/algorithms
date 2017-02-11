var Person = function(firstAndLast) {
    var splitArr = firstAndLast.split(" ");
    firstName = splitArr[0];
    lastName = splitArr[1];
    this.getFullName = function(){
      return firstName + " "+ lastName;
    };
    this.getFirstName = function(){
      return firstName;
    };
    this.getLastName = function(){
      return lastName;
    };
    this.setFirstName = function(first){
      firstName = first;
    };
    this.setLastName = function(last){
      lastName = last;
    };
    this.setFullName = function(firstAndLast){
      var splitArr = firstAndLast.split(" ");
      firstName= splitArr[0];
      lastName = splitArr[1];
    };
};



var bob = new Person('Bob Ross');
console.log(bob.getFirstName());
console.log(bob.getLastName());
console.log(bob.getFullName());
