#include <optional>
#include <vector>

class quick_find {
public:
  quick_find(int count) : count_(count), ids_(count) {
    for (int i = 0; i < this->count_; ++i) {
      this->ids_[i] = i;
    }
  }

  int get_count() const { return this->count_; }

  bool is_connected(int p, int q) const {
    return this->find(p) == this->find(q);
  }

  std::optional<int> find(int p) const {
    if (p < 0 || p >= this->ids_.size()) {
      return std::nullopt;
    }
    return this->ids_[p];
  }

  virtual void make_union(int p, int q) {
    std::optional<int> p_id = this->find(p);
    std::optional<int> q_id = this->find(q);
    if (!p_id || !q_id) {
      return;
    }
    if (p_id.value() == q_id.value()) {
      return;
    }
    for (auto &id : this->ids_) {
      if (id == p_id.value()) {
        id = q_id.value();
      }
    }
    --this->count_;
  }

protected:
  int count_;
  std::vector<int> ids_;
};