#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>


class Medicion {
  protected:
    std::chrono::system_clock::time_point time_;
    virtual void stamp(void) {
        std::cout << "\tMedicion.stamp()" << std::endl;
        time_ = std::chrono::system_clock::now();
    }
  public:
    Medicion() { std::cout  << "\tMedicion" << std::endl; stamp(); }
    virtual ~Medicion() { std::cout  << "\t~Medicion" << std::endl; }
    virtual void Print() const = 0;
};


class MedicionLidar : public Medicion {
  protected:
    std::vector<double> data_;
  public:
    MedicionLidar(std::vector<double> &data) : data_(std::move(data)) { std::cout  << "\tMedicionLidar" << std::endl; }
    virtual ~MedicionLidar() { std::cout  << "\t~MedicionLidar" << std::endl; }
    void Print() const override {
        std::time_t stamp = std::chrono::system_clock::to_time_t(time_);
        std::cout << "\tMedicionLidar->Print()\n\t";
        std::cout << std::ctime(&stamp) << "\t";
        for (const auto& e : data_) {
            std::cout << ", " << e;
        }
        std::cout << std::endl;
    }
};


class MedicionGPS : public Medicion {
  protected:
    std::vector<double> data_;
  public:
    MedicionGPS(std::vector<double> &data) : data_(std::move(data)) { std::cout  << "\tMedicionGPS" << std::endl; }
    virtual ~MedicionGPS() { std::cout  << "\t~MedicionGPS" << std::endl; }
    void Print() const override {
        std::time_t stamp = std::chrono::system_clock::to_time_t(time_);
        std::cout << "\tMedicionGPS->Print()\n\t";
        std::cout << std::ctime(&stamp) << "\t";
        for (const auto& e : data_) {
            std::cout << ", " << e;
        }
        std::cout << std::endl;
    }
};


class MedicionCamara : public Medicion {
  protected:
    std::vector<std::vector<int>> data_;
  public:
    MedicionCamara(std::vector<std::vector<int>> &data) : data_(std::move(data)) { std::cout  << "\tMedicionCamara" << std::endl; }
    virtual ~MedicionCamara() { std::cout  << "\t~MedicionCamara" << std::endl; }
    void Print() const override {
        std::time_t stamp = std::chrono::system_clock::to_time_t(time_);
        std::cout << "\tMedicionCamara->Print()\n";
        std::cout << "\t" << std::ctime(&stamp);
        for (const auto& r : data_) {
            std::cout << "\t";
            for (const auto& e : r) {
                std::cout << e << ", ";
            }
            std::cout << std::endl;
        }
    }
};


class Sensor {
  public:
    Sensor() { std::cout  << "\tSensor" << std::endl; }
    virtual ~Sensor() { std::cout  << "\t~Sensor" << std::endl; }
    virtual Medicion* medir() = 0;
};


class Lidar : public Sensor {
  private:
    double res_, ap_;
  public:
    Lidar(double res, double ap) : res_(res), ap_(ap) { std::cout << "\tLidar(res, ap)" << std::endl; }
    Lidar(const Lidar& o) : res_(o.res_), ap_(o.ap_) { std::cout << "\tLidar(otro)" << std::endl; }
    ~Lidar() { std::cout << "\t~Lidar()" << std::endl; }
    const Lidar& operator=(const Lidar& o) {
        res_ = o.res_;
        ap_ = o.ap_;
        std::cout << "\tLidar.operator=()" << std::endl;
        return *this;
    }
    bool operator==(const Lidar& o) const {
        std::cout << "\tLidar.operator==()" << std::endl;
        return res_ == o.res_ && ap_ == o.ap_;
    }
    Medicion* medir(void) override {
        std::cout << "\n\tLidar->medir()\n";
        std::vector<double> v(ap_ / res_);
        return new MedicionLidar(v);
    }
};


class GPS : public Sensor {
  private:
    double pre_;
  public:
    GPS(double pre) : pre_(pre) { std::cout << "\tGPS(pre)" << std::endl; }
    GPS(const GPS& o) : pre_(o.pre_) { std::cout << "\tGPS(otro)" << std::endl; }
    ~GPS() { std::cout << "\t~GPS()" << std::endl; }
    const GPS& operator=(const GPS& o) {
        pre_ = o.pre_;
        std::cout << "\tGPS.operator=()" << std::endl;
        return *this;
    }
    bool operator==(const GPS& o) const {
        std::cout << "\tGPS.operator==()" << std::endl;
        return pre_ == o.pre_;
    }
    Medicion* medir(void) override {
        std::cout << "\n\tGPS->medir()\n";
        std::vector<double> v(3);
        return new MedicionGPS(v);
    }
};


class Camara : public Sensor {
  private:
    size_t h_, w_;
  public:
    Camara(size_t h, size_t w) : h_(h), w_(w) { std::cout << "\tCamara(h, w)" << std::endl; }
    Camara(const Camara& o) : h_(o.h_), w_(o.w_) { std::cout << "\tCamara(otro)" << std::endl; }
    ~Camara() { std::cout << "\t~Camara()" << std::endl; }
    const Camara& operator=(const Camara& o) {
        h_ = o.h_;
        w_ = o.w_;
        std::cout << "\tCamara.operator=()" << std::endl;
        return *this;
    }
    bool operator==(const Camara& o) const {
        std::cout << "\tCamara.operator==()" << std::endl;
        return h_ == o.h_ && w_ == o.w_;
    }
    Medicion* medir(void) override {
        std::cout << "\n\tCamara->medir()\n";
        std::vector<std::vector<int>> v(h_);
        for (auto & e : v) {
            e.reserve(w_);
            for (size_t i = 0; i < e.capacity(); i++) {
                e.emplace_back('F');
            }
        }
        return new MedicionCamara(v);
    }
};


class AutoAutonomo {
  private:
    std::vector<Sensor *> sensors_;
  public:
    void AddSensor(Sensor* sens) {
        sensors_.emplace_back(sens);
    }
    void Log(void) const {
        for (const auto sensor : sensors_) {
            Medicion *medicion = sensor->medir();
            medicion->Print();
            delete medicion;
        }
    }
    AutoAutonomo() {std::cout << "\tAutoAutonomo()" << std::endl;}
    ~AutoAutonomo() {
        std::cout << "\t~AutoAutonomo()" << std::endl;
        for (const auto sensor : sensors_) {
            delete sensor;
        }
    }
};


int main(void) {
    std::cout << "Construcciones:" << std::endl;
    AutoAutonomo *autito = new AutoAutonomo();
    Sensor *ublox = new GPS(0.1);
    Camara *GoPro = new Camara(4, 5);
    Lidar *lidar = new Lidar(10, 270);

    autito->AddSensor(ublox);
    autito->AddSensor(GoPro);
    autito->AddSensor(lidar);

    std::cout << "\nLog:" << std::endl;
    autito->Log();

    std::cout << "\nDestrucciones:" << std::endl;
    delete autito;

    return 0;
}