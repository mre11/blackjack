#!groovy
node {
	stage 'checkout'
		checkout scm

	stage 'build'
		bat "\"${tool 'MSBuild'}\" Blackjack.sln /p:Configuration=Release /p:Platform=\"x64\""

	stage 'test'
		bat "bin\x64\Release\utBlackjack.exe"

}
