#pragma once
#include "Song.h"


class Playlist {
private:
	Song* songs_;
	size_t count_;
	size_t capacity_;

	void resize() {
		capacity_ *= 2;

		Song* newSongs = new Song[capacity_];

		for (size_t i = 0; i < count_; i++)
		{
			newSongs[i] = std::move(songs_[i]);
		}
		delete[] songs_;

		songs_ = newSongs;
	}

	void addSong(const Song& song) {
		if (count_ >= capacity_)
		{
			resize();
		}

		songs_[count_++] = song;
	}

	void addSong(Song&& song) noexcept {
		if (count_ >= capacity_)
		{
			resize();
		}

		songs_[count_++] = std::move(song);
	}


	void removeSong(size_t idx) {
		if (idx >= count_)
		{
			return;
		}

		for (size_t i = idx; i < count_ - 1; i++)
		{
			songs_[i] = std::move(songs_[i + 1]);
		}

		count_--;
	}

	void sortByDuration() {
		for (size_t i = 0; i < count_ - 1; i++)
		{
			for (size_t j = 0; j < count_ - i - 1; j++)
			{
				if (songs_[j] > songs_[j + 1])
				{
					std::swap(songs_[j], songs_[j + 1]);
				}
			}
		}
	}
};
