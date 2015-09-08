/**
 * Javascript file where we import
 * our compiled hello.cc module.
 * @author juanvallejo
 */

var hello = require('./build/Release/hello.node');

// output the returned string of our module's
// only method
console.log(hello.sayHello());