document.addEventListener("DOMContentLoaded", function() {
    // Вопрос 1: Выбор ответа
    const answerBtns = document.querySelectorAll('.answer-btn');
    answerBtns.forEach(function(button) {
        button.addEventListener('click', function() {
            const isCorrect = button.getAttribute('data-correct') === 'true';
            const feedback = button.parentElement.querySelector('.feedback');

            if (isCorrect) {
                button.classList.add('correct');
                feedback.textContent = "Верно!";
                feedback.classList.add('correct');
            } else {
                button.classList.add('incorrect');
                feedback.textContent = "Неверно";
                feedback.classList.add('incorrect');
            }

            // Disable all buttons after an answer is chosen
            answerBtns.forEach(btn => btn.disabled = true);
        });
    });

    // Вопрос 2: Текстовый ответ
    const submitBtn = document.querySelector('.submit-btn');
    submitBtn.addEventListener('click', function() {
        const userAnswer = document.getElementById('user-answer').value.trim();
        const feedback = submitBtn.parentElement.querySelector('.feedback');

        if (userAnswer.toLowerCase() === "//") {
            feedback.textContent = "Верно!";
            feedback.classList.add('correct');
            submitBtn.classList.add('correct');
        } else {
            feedback.textContent = "Неверно";
            feedback.classList.add('incorrect');
            submitBtn.classList.add('incorrect');
        }
    });
});

