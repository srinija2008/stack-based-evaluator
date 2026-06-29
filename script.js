function precedence(op) {
    if (op === '+' || op === '-') return 1;
    if (op === '*' || op === '/') return 2;
    if (op === '^') return 3;
    return 0;
}

function infixToPostfix(expr) {

    let stack = [];
    let postfix = "";

    for (let ch of expr) {

        if (ch === " ")
            continue;

        if (!isNaN(ch) || /[A-Za-z]/.test(ch)) {
            postfix += ch;
        }

        else if (ch === '(') {
            stack.push(ch);
        }

        else if (ch === ')') {

            while (stack.length && stack[stack.length - 1] !== '(') {
                postfix += stack.pop();
            }

            stack.pop();
        }

        else {

            while (
                stack.length &&
                precedence(stack[stack.length - 1]) >= precedence(ch)
            ) {
                postfix += stack.pop();
            }

            stack.push(ch);
        }
    }

    while (stack.length) {
        postfix += stack.pop();
    }

    return postfix;
}

function evaluatePostfix(expr) {

    const stack = [];

    for (let ch of expr) {

        if (!isNaN(ch) && ch !== " ") {
            stack.push(Number(ch));
        }

        else {

            let b = stack.pop();
            let a = stack.pop();

            switch (ch) {

                case '+':
                    stack.push(a + b);
                    break;

                case '-':
                    stack.push(a - b);
                    break;

                case '*':
                    stack.push(a * b);
                    break;

                case '/':
                    stack.push(a / b);
                    break;
            }
        }
    }

    return stack.pop();
}

function processExpression() {

    const expr = document.getElementById("expression").value;

    let isInfix = false;

    for (let i = 0; i < expr.length; i++) {

        if (
            expr[i] === '(' ||
            expr[i] === ')' ||
            /[A-Za-z]/.test(expr[i]) ||
            (i > 0 &&
                !isNaN(expr[i]) &&
                ['+','-','*','/'].includes(expr[i - 1]))
        ) {
            isInfix = true;
            break;
        }
    }

    if (isInfix) {

        let postfix = infixToPostfix(expr);

        if (/[A-Za-z]/.test(postfix)) {

            document.getElementById("result").innerText =
                "Postfix Expression: " + postfix;

        } else {

            let result = evaluatePostfix(postfix);

            document.getElementById("result").innerText =
                "Postfix Expression: " + postfix +
                "\nResult: " + result;
        }

    } else {

        let result = evaluatePostfix(expr);

        document.getElementById("result").innerText =
            "Result: " + result;
    }
}
