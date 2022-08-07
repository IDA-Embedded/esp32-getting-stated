pipeline {
    agent any


    environment {
        // most likely should not be changed
        ARTIFACT_GIT_PATH = '/home/server/Jenkins/Artifacts/'
        // -------------------------------------------------------------------------- //
        PROJECT_NAME_REMOTE = 'IDAE_ESP_GETTING_STARTED/'
        DEVICE_NAME   = 'server'
        PROJECT_NAME  = 'IDAE_ESP_GETTING_STARTED'
    }
    stages{




    stage('Static Code Analysis'){
           
    steps {
        sh 'make cppcheck'
    }
    }
        stage('Code Complexity Analysis'){   
            steps {
            echo "Doing Complexity"
                sh 'make complexity'
            }
    }
     stage('Build target'){
            steps{
                echo "Build target"    
                         
             
               sh '''
                . /home/server/esp/esp-idf/export.sh;
                export PATH=/home/server/.local/bin/:$PATH;                   
                make ci
               '''
               
            }
        }



        stage('Build artifact'){
            steps{
                echo "Building artifact .... "
                sh './tools/build_artifact.sh ${PROJECT_NAME}'
            }
        }
        stage('Publish artifact'){
            steps{
                echo "Publicing artifact ... "
                withCredentials([gitUsernamePassword(credentialsId: '1b433a3d-2e81-4e4c-aff9-ab1fea8258ca',
                 gitToolName: 'git-tool')]) {
                     sh './tools/publishArtifact.sh ${PROJECT_NAME_REMOTE} ${ARTIFACT_GIT_PATH}'
                }  
               

            }
        }


    }
        post{
            always{
                   recordIssues(enabledForFailure: true, aggregatingResults: true, tools: [cppCheck(pattern: 'docs/cppcheck/cppcheck.xml')])
                publishHTML (target : [allowMissing: false,
                alwaysLinkToLastBuild: true,
                keepAll: true,
                reportDir: 'docs/complexity',
                reportFiles: 'complexity.html',
                reportName: 'Complexity report',
                reportTitles: 'The Report'])

            }
            success {
                echo "successfully build the project!"
             
          
            }
            
        }
    
}
