# Configure the GCP provider
provider "google" {
  project = var.project_id  # Specify the GCP project ID
  region  = var.region      # Specify the GCP region
}

# Define variables for project and region
variable "project_id" {
  description = "GCP project ID"
}

variable "region" {
  description = "GCP region"
  default     = "us-central1"
}

variable "zone" {
  description = "GCP zone"
  default     = "us-central1-a"
}

# Create a new network
resource "google_compute_network" "vpc_network" {
  name                    = "terraform-network"
  auto_create_subnetworks = true
}

# Create a firewall rule to allow SSH access
resource "google_compute_firewall" "default" {
  name    = "allow-ssh"
  network = google_compute_network.vpc_network.name

  allow {
    protocol = "tcp"
    ports    = ["22"]  # Allow SSH access
  }

  source_ranges = ["0.0.0.0/0"]  # Allow traffic from any IP
}

# Create an instance
resource "google_compute_instance" "vm_instance" {
  name         = "terraform-instance"
  machine_type = "e2-micro"  # Smallest instance type
  zone         = var.zone

  # Use the latest Ubuntu image
  boot_disk {
    initialize_params {
      image = "ubuntu-os-cloud/ubuntu-2004-lts"
    }
  }

  # Use the VPC network created earlier
  network_interface {
    network = google_compute_network.vpc_network.name

    access_config {
      # Include this section to assign a public IP to the instance
    }
  }

  # Metadata to pass the SSH key
  metadata = {
    ssh-keys = "terraform:${file("~/.ssh/id_rsa.pub")}"  # Add your SSH public key
  }

  tags = ["ssh"]
}

# Output the instance's public IP address
output "instance_public_ip" {
  value = google_compute_instance.vm_instance.network_interface[0].access_config[0].nat_ip
}
