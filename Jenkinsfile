pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                // Вказуємо вашу гілку main і посилання на ваш репозиторій
                git branch: 'main', url: 'https://github.com/danilokkf/lab4_jenkins.git'
            }
        }
        
        stage('Build') {
            steps {
                // 1. Відновлюємо NuGet пакети (Restore)
                // 2. Компілюємо проект (Rebuild)
                // УВАГА: Перевірте, що шлях до MSBuild.exe правильний! (Тут для VS 2022 Community)
                bat '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /t:Restore;Rebuild /p:Configuration=Release'
            }
        }

        stage('Test') {
            steps {
                // Запускаємо скомпільований тест і генеруємо XML звіт
                bat 'x64\\Release\\test_repos.exe --gtest_output=xml:test_report.xml'
            }
        }
    }

    post {
        always {
            // Публікуємо результати тестів у Jenkins
            junit 'test_report.xml'
        }
    }
}