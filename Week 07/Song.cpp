#include "Song.h"
#pragma warning (disable: 4996)
#include <print>
#include <iostream>

void Song::free()
{
	delete[] title_;
	delete[] artist_;
	title_ = nullptr;
	artist_ = nullptr;
}

void Song::copyFrom(const Song& other)
{
	duration_ = other.duration_;

	title_ = new char[strlen(other.title_) + 1];
	strcpy(title_, other.title_);

	artist_ = new char[strlen(other.artist_) + 1];
	strcpy(artist_, other.artist_);
}

void Song::moveFrom(Song&& other) noexcept
{
	duration_ = other.duration_;
	title_ = other.title_;
	artist_ = other.artist_;

	other.duration_ = 0;
	other.title_ = nullptr;
	other.artist_ = nullptr;
}

Song::Song() : title_(nullptr), artist_(nullptr), duration_(0)
{
}

Song::Song(const char* title, const char* artist, int duration)
{
	setTitle(title);
	setArtist(artist);
	setDuration(duration);
}

void Song::setTitle(const char* title)
{
	if (!title || title_ == title)
	{
		return;
	}

	delete[] title_;

	title_ = new char[strlen(title) + 1];
	strcpy(title_, title);
}

void Song::setArtist(const char* artist)
{
	if (!artist || artist_ == artist)
	{
		return;
	}

	delete[] artist_;

	artist_ = new char[strlen(artist) + 1];
	strcpy(artist_, artist);
}

void Song::setDuration(int duration)
{
	if (duration <= 0)
	{
		return;
	}

	duration_ = duration;
}


Song::Song(const Song& other)
{
	copyFrom(other);
}

Song::Song(Song&& other) noexcept
{
	moveFrom(std::move(other));
}

Song& Song::operator=(const Song& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	
	return *this;
}

Song& Song::operator=(Song&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Song::~Song()
{
	free();
}

const char* Song::getTitle() const
{
	return title_;
}

const char* Song::getArtist() const
{
	return artist_;
}

int Song::getDuration() const
{
	return duration_;
}

bool Song::operator==(const Song& other) const
{
	return duration_ == other.duration_ &&
		strcmp(title_, other.title_) == 0 &&
		strcmp(artist_, other.artist_) == 0;
}

std::ostream& operator<<(std::ostream& os, const Song& s)
{
	std::println(
		os,
		"Title: {}, Artist: {}, Duration: {}",
		s.title_,
		s.artist_,
		s.duration_);

	return os;
}
