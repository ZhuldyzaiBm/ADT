#include "set.h"

bool equal(const std::string& s1, const std::string& s2) {
  if (s1.size() != s2.size())
    return false;
  for (size_t count = 0; count < s1.size(); count++) {
    if (tolower(s1[count]) != tolower(s2[count]))
      return false;
  }
  return true;
}

size_t hash(const std::string& s) {
  size_t hashRes = 0;
  size_t count = s.size();
  for (size_t i = 0; i < count; i++) {
    size_t power = 1;
    for (size_t j = 0; j < count - i - 1; j++) {
      power *= 31;
    }
    hashRes += tolower(s[i]) * power;
  }
  return hashRes;
}

set::set(const set& s)
    : bucket_array(new std::list<std::string>[s.bucket_array_size]),
      bucket_array_size(s.bucket_array_size), set_size(0) {
  for (size_t i = 0; i < s.bucket_array_size; i++) {
    for (auto el = s.bucket_array[i].begin(); el != s.bucket_array[i].end();
         el++) {
      insert(*el);
    }
  }
}

set::set(std::initializer_list<std::string> ilist) {
  set_size = 0;
  bucket_array = new std::list<std::string>[4];
  bucket_array_size = 4;
  for (auto el : ilist) {
    insert(el);
  }
}

set &set::operator=(const set& s) {
  clear();
  std::list<std::string> *temp;
  temp = new std::list<std::string>[s.bucket_array_size];
  for (size_t i = 0; i < s.bucket_array_size; i++) {
    for (auto el = s.bucket_array[i].begin(); el != s.bucket_array[i].end();
         el++) {
      size_t newIndex = hash(*el) % (s.bucket_array_size);
      temp[newIndex].push_back(*el);
      set_size++;
    }
  }
  delete[] bucket_array;
  bucket_array = temp;
  bucket_array_size = s.bucket_array_size;
  return *this;
}

bool set::insert(std::string val) {
  size_t hashVal = hash(val);
  size_t bucketIndex = hashVal % bucket_array_size;
  if (!contains(val)) {
    if (loadfactor() >= max_load_factor) {
      size_t newBucketSize = bucket_array_size * 2;
      std::list<std::string> *newBuckets;
      newBuckets = new std::list<std::string>[newBucketSize];

      for (size_t i = 0; i < bucket_array_size; i++) {
        for (auto el = bucket_array[i].begin();
             el != bucket_array[i].end(); el++) {
          size_t newIndex = hash(*el) % (newBucketSize);
          newBuckets[newIndex].push_back(*el);
        }
      }
      delete[] bucket_array;
      bucket_array = newBuckets;
      bucket_array_size = newBucketSize;
    }
    bucketIndex = hashVal % bucket_array_size;
    bucket_array[bucketIndex].push_back(val);
    set_size++;
    return true;
  }
  return false;
}

bool set::contains(std::string val) const {
  size_t hashVal = hash(val);
  size_t bucketIndex = hashVal % bucket_array_size;
  for (const auto &el : bucket_array[bucketIndex]) {
    if (equal(el, val))
      return true;
  }
  return false;
}

bool set::remove(std::string val) {
  size_t hashVal = hash(val);
  size_t bucketIndex = hashVal % bucket_array_size;
  for (auto el = bucket_array[bucketIndex].begin();
       el != bucket_array[bucketIndex].end(); ++el) {
    if (equal(*el, val)) {
      bucket_array[bucketIndex].erase(el);
      set_size--;
      return true;
    }
  }
  return false;
}

void set::clear() {
  for (size_t count = 0; count < bucket_array_size; count++) {
    bucket_array[count].clear();
  }
  set_size = 0;
}

size_t set::size() const { return set_size; }

bool set::empty() const { return set_size == 0; }

set::~set() { delete[] bucket_array; }