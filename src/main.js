
class Expression {
    // class methods and properties go here
}

const mathjs = require('mathjs');
const readlineSync = require('readline-sync');

// Ask the user to input a mathematical expression.
const expression = readlineSync.question('Enter a mathematical expression: ');

// Parse the input expression to identify the variables and operators.
const node = mathjs.parse(expression);

// Apply the derivative rules to each term in the expression.
const derivative = node.derivative('x');

// Combine the derivative terms to produce the final derivative expression.
const simplified = derivative.simplify();

// Display the final derivative expression to the user.
console.log(`The derivative of ${expression} is ${simplified.toString()}`);
