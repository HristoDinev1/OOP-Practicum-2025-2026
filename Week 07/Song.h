#pragma once
#include <fstream>
#include <compare>

class Song {
private:
	char* title_;
	char* artist_;
	int duration_;

	void free();
	void copyFrom(const Song& other);
	void moveFrom(Song&& other) noexcept;

public:
	Song();
	Song(const char* title, const char* artist, int duration);

	void setTitle(const char* title);
	void setArtist(const char* artist);
	void setDuration(int duration);

	Song(const Song& other);
	Song(Song&& other) noexcept;
	Song& operator=(const Song& other);
	Song& operator=(Song&& other) noexcept;

	~Song();

	const char* getTitle() const;
	const char* getArtist() const;
	int getDuration() const;

	auto operator<=>(const Song& other) const {
		if (auto cmp = strcmp(artist_, other.artist_) <=> 0; cmp != 0)
		{
			return cmp;
		}

		if (auto cmp = strcmp(title_, other.title_) <=> 0; cmp != 0)
		{
			return cmp;
		}

		return duration_ <=> other.duration_;
	}

	bool operator==(const Song& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Song& s);
};
