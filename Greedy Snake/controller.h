#pragma once

class Controller
{
public:
	Controller():m_Speed(200),m_Key(1),m_Score(0) {}
	void Start();
	void Select();
	void DrawGame();
	int PlayGame();
	void UpdateScore(const int&);
	void RewriteScore();
	int Menu();
	void Game();
	int GameOver();

private:
	int m_Speed;
	int m_Key;
	int m_Score;
};
