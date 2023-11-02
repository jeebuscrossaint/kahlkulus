const math = require('mathjs');
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter a mathematical expression: ', (expression) => {
  try {
    const derivative = math.derivative(expression, 'x').toString();
    console.log('Derivative:', derivative);
  } catch (error) {
    console.log('Invalid expression');
  }
  rl.close();
});
